#include <Arduino.h>

void sendMotorCommand(char commandType, long speed) {
  // 构造命令数据
  byte command[8];
  
  // 固定值
  command[0] = 0x19;
  command[1] = 0x88;
  
  // 命令种类
  command[2] = commandType;
  
  // 命令数据
  command[3] = (speed >> 24) & 0xFF; // 高位
  command[4] = (speed >> 16) & 0xFF;
  command[5] = (speed >> 8) & 0xFF;
  command[6] = speed & 0xFF; // 低位
 
  // 结尾固定值
  command[7] = 0x11;
  // 发送命令数据
  Serial.write(command, 8);
}

void setup() {
  // 初始化串口
  Serial.begin(115200);
}

void loop() {
  // 示例：设定第一个电机的转速为100
  sendMotorCommand('M', 200);
  
  // 等待一段时间
  
  // 示例：设定第二个电机的转速为-50
  sendMotorCommand('m', 200);
  
  // 等待一段时间
  delay(1000);
}
