# Bicycle-Rent-Project

Bicycle-Rent-Project, **Arduino + ESP8266 + RFID** donanımı ile çalışan bir bisiklet kiralama otomasyonudur. Kullanıcı RFID kartını okuttuğunda kiralama başlatılır; aynı kart tekrar okutulduğunda kiralama sonlandırılır ve ücret hesaplanarak veritabanına kaydedilir.

## 📌 Proje Özeti

Bu proje iki ana parçadan oluşur:

1. **Donanım katmanı (Arduino/ESP8266):**
   RFID kart UID bilgisini okuyup Wi‑Fi üzerinden backend API'ye gönderir.
2. **Backend katmanı (Flask + MySQL):**
   Kullanıcı/kiralama kayıtlarını tutar, kiralama açma-kapama işlemlerini yönetir ve ödeme kaydı oluşturur.

## 🧰 Kullanılan Teknolojiler

### Donanım
- Arduino UNO (veya uyumlu kart)
- ESP8266
- MFRC522 RFID okuyucu
- RFID kart / anahtarlık

### Yazılım
- Arduino C/C++
- Python (Flask, Flask-CORS)
- MySQL
- HTTP tabanlı API iletişimi

## 🔁 Çalışma Akışı

1. Kullanıcı RFID kartını okutur.
2. ESP8266, kart UID bilgisi ile backend'e istek gönderir.
3. Backend ilgili kullanıcıyı bulur:
   - Aktif kiralama yoksa yeni kiralama kaydı açar.
   - Aktif kiralama varsa kiralamayı kapatır, süre/ücret hesabı yapar ve ödeme kaydı oluşturur.
4. Veriler MySQL veritabanına yazılır.

## 📁 Proje Yapısı

- `arduino/arduino.ino` ve `arduino/esp8266.ino`: Donanım tarafı kodları
- `backend/app.py`: Flask API uçları ve kiralama mantığı
- `backend/db.py`: MySQL bağlantı ayarları
- `database/`: Veritabanı ile ilgili notlar/dokümanlar

## ⚙️ Kurulum

### 1) Backend kurulumu

```bash
cd backend
python -m venv .venv
source .venv/bin/activate   # Windows için: .venv\Scripts\activate
pip install flask flask-cors mysql-connector-python
