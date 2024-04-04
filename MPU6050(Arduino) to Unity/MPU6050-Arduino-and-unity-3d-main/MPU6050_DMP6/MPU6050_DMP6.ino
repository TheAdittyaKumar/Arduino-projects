#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"

MPU6050 mpu;

// MPU control/status vars
bool dmpReady = false;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];

// orientation/motion vars
Quaternion q;

void setup() {
  Wire.begin();
  Wire.setClock(400000);
  Serial.begin(115200);
  mpu.initialize();
  devStatus = mpu.dmpInitialize();

  mpu.setXGyroOffset(54);
  mpu.setYGyroOffset(-21);
  mpu.setZGyroOffset(5);

  if (devStatus == 0) {
    mpu.setDMPEnabled(true);
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
    Serial.println("DMP Initialization failed.");
  }
}

void loop() {
  if (!dmpReady) return;

  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    SendQuaternion();
  }
}

void SendQuaternion() {
  mpu.dmpGetQuaternion(&q, fifoBuffer);
  Serial.print("QUAT,");
  Serial.print(q.w); Serial.print(",");
  Serial.print(q.x); Serial.print(",");
  Serial.print(q.y); Serial.print(",");
  Serial.println(q.z);
}

// Define other Send functions as needed...
