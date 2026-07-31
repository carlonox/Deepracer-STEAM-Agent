#!/usr/bin/env python3
"""explorer.py v5 — Simplified, long strokes, no wiggles, detailed camera logs"""
import serial,requests,re,time,threading,urllib.request,cv2,numpy as np,random
U="http://localhost:5001";P="${DEEPRACER_API_PASSWORD}";C="http://localhost:8080/snapshot?topic=/camera_pkg/display_mjpeg"
st="idle";tm=0;dc=0;cf=False;ign=0.0

def el():
 global cf
 try:
  s=serial.Serial("/dev/ttyUSB0",115200,timeout=1);s.dtr=False;time.sleep(0.1);s.rts=False;time.sleep(0.5);s.reset_input_buffer()
  print("[ESP] OK",flush=True)
  while True:
   l=s.readline()
   if l and b"collision" in l:
    if st=="forward":cf=True;print("[ESP] COLISION!",flush=True)
 except:print("[ESP] No disponible",flush=True)
threading.Thread(target=el,daemon=True).start();time.sleep(2)
ss=requests.Session();r=ss.get(f"{U}/login",timeout=10)
cs=re.search(r'csrf-token" content="([^"]+)"',r.text).group(1)
ck=re.search(r'session=([^;]+)',r.headers.get("Set-Cookie","")).group(1)
ss.post(f"{U}/login",data={"csrf_token":cs,"password":P},headers={"X-CSRFToken":cs,"Content-Type":"application/x-www-form-urlencoded","Cookie":f"session={ck}"})
h=lambda:{"Content-Type":"application/json","X-Requested-With":"XMLHttpRequest","X-CSRFToken":cs,"Cookie":f"session={ck}"}
ss.put(f"{U}/api/drive_mode",json={"drive_mode":"manual"},headers=h());ss.put(f"{U}/api/start_stop",json={"start_stop":"start"},headers=h())
print("[EXPLORER] Ready!",flush=True)
def cal(t):
 # Zona muerta: normalizado (0,1] -> real [0.5,1]; 0 = parada. Verificado 2026-07-31.
 if abs(t)<1e-6:return 0.0
 return (1.0 if t>0 else -1.0)*min(1.0,0.5+0.5*abs(t))
def go(a,t):
 try:ss.put(f"{U}/api/manual_drive",json={"angle":a,"throttle":cal(t),"max_speed":1.0},headers=h(),timeout=1)
 except:pass
def check_cam():
 try:
  r=urllib.request.urlopen(C,timeout=1)
  i=cv2.imdecode(np.frombuffer(r.read(),np.uint8),cv2.IMREAD_COLOR)
  if i is None:return False
  h,w=i.shape[:2];roi=cv2.cvtColor(i[h//3:2*h//3,w//3:2*w//3],cv2.COLOR_BGR2GRAY)
  m=np.mean(roi);s=np.std(roi)
  e=cv2.Canny(roi,50,150);ed=np.count_nonzero(e)/(roi.shape[0]*roi.shape[1])
  hsv=cv2.cvtColor(i,cv2.COLOR_BGR2HSV)
  bl=cv2.inRange(hsv[h//3:2*h//3,w//3:2*w//3],np.array([80,50,30]),np.array([145,255,255]))
  bp=np.count_nonzero(bl)/(roi.shape[0]*roi.shape[1])
  obs=bp>0.15 or (m<60) or (m<110 and s<15) or ed>0.35
  print(f"[CAM] b={m:.0f} s={s:.0f} e={ed:.0%} blue={bp:.0%} obs={obs}",flush=True)
  return obs
 except Exception as ex:print(f"[CAM] Error: {ex}",flush=True);return False
try:
 while True:
  n=time.time()
  if st=="idle":
   go(0,0)
   if n<ign:st="go";tm=n;print("[FORCE]",flush=True);continue
   if check_cam():st="backup";tm=n
   else:st="go";tm=n
  elif st=="go":
   if n-tm<6.0:go(dc,-0.10)
   else:go(0,0);print("[STOP]",flush=True);st="idle";tm=n
  elif st=="backup":
   if n-tm<1.5:go(0,0.10)
   elif n-tm<3.0:go(random.choice([-0.8,0.8]),-0.05)
   else:ign=n+8.0;dc=random.choice([-0.3,0.3]);print("[ESCAPE]",flush=True);st="go";tm=n
  time.sleep(0.05)
except KeyboardInterrupt:pass
finally:go(0,0);ss.put(f"{U}/api/start_stop",json={"start_stop":"stop"},headers=h());print("[STOPPED]",flush=True)
