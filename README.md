# Bicycle-Rent-Project

Bu proje, **ESP8266** ve **Arduino** kullanarak geliştirilen, **RFID kartlar ile çalışan bir kiralama sistemidir**. Kullanıcılar RFID kartlarını okuttuklarında bir kiralama işlemi başlatılır. Aynı kart tekrar okutulduğunda işlem sonlandırılır ve kira ücreti veritabanına kaydedilir.

## 🚀 Proje Hakkında

Sistem, IoT donanımı ile Python tabanlı bir backend arasında veri iletişimi kurar. RFID okuyucu ile kullanıcıların kart bilgileri alınır ve bu veriler backend API'sine gönderilerek işlem başlatılır veya sonlandırılır.

### ⚙️ Kullanılan Teknolojiler

#### Donanım:
- ESP8266 Wi-Fi Modülü
- Arduino UNO (veya uyumlu)
- MFRC522 RFID Okuyucu
- RFID Kartlar / Anahtarlıklar

#### Yazılım:
- Arduino C/C++ (ESP8266 için)
- Python (Flask)
- Mysql 
- HTTP üzerinden veri iletimi 

## 🔁 Akış

1. Kullanıcı RFID kartını cihaza okutur.
2. ESP8266, kart UID'sini Python backend'e gönderir.
3. Backend:
   - Eğer kullanıcı yeni bir kiralama başlatmadıysa → **Kiralama başlatılır**.
   - Eğer kullanıcı zaten kiralama yaptıysa → **Kiralama sonlandırılır ve ücret hesaplanır.**
4. İşlem sonunda veriler veritabanına kaydedilir.

## 🛠 Kurulum

### Donanım Kurulumu
- Arduino ile MFRC522 bağlantısı yapılır.
- ESP8266, Wi-Fi ağına bağlanacak şekilde programlanır.
- Arduino IDE üzerinden gerekli kütüphaneler kurulur:  
  - `MFRC522`
  - `ESP8266WiFi`
  - `HTTPClient`
  - `ArduinoJson`

###
-Proje Geliştirme Aşamasındadır-
