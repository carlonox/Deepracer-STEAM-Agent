DeepRacer web API:
- IP: 10.203.150.56, puerto 5001 (HTTP, no HTTPS)
- Password API web: 48AW5fAB (diferente de SSH)
- Login: GET /login → extraer CSRF del meta tag → POST /login con password + header X-CSRFToken
- La cookie session tiene flag Secure, hay que inyectarla manualmente en el cookie jar
- Endpoints: PUT /api/drive_mode, PUT /api/start_stop, PUT /api/manual_drive
- Headers necesarios: X-CSRFToken, X-Requested-With: XMLHttpRequest
- Script de control: /workspace/hermes/scripts/drive_test.py