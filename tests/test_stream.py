
import cv2

# Replace this with your actual ESP32-CAM stream URL.
STREAM_URL = "http://192.168.137.92:8080/"

cap = cv2.VideoCapture(STREAM_URL)

if not cap.isOpened():
    raise RuntimeError(
        "Could not open camera stream. Check the URL and Wi-Fi."
    )

print("Camera connected. Press Q to quit.")

while True:
    success, frame = cap.read()

    if not success:
        print("Could not read frame.")
        break

    cv2.imshow("ESP32-CAM Video", frame)

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()
