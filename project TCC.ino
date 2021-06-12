#define zc 2
#define dimmer 5
int funcao = 0;
volatile float p = 0;
float p2 = 0;
float LDR = A4;
float MOD = A5;
float setpoint = 0;
volatile float valmod = 0;
volatile float valldr =0;
void zeroCross(){
 if(p < 0) p = 0;
 if(p > 0.96) p = 0.96;
 long t1 = 8200L * (1L - p);
 delayMicroseconds(t1);
 digitalWrite(dimmer, HIGH);
 delayMicroseconds(6);
 digitalWrite(dimmer, LOW);
}
17
void setup() {
 pinMode(zc,INPUT);
 pinMode(dimmer,OUTPUT);
 attachInterrupt(0, zeroCross, RISING);
 pinMode(LDR,INPUT);
 pinMode(MOD,INPUT);
 Serial.begin(9600);
 }
void loop() {
 if(funcao == 0)p = 0;
 if(funcao != 0){
 while(setpoint != valldr && p != 0 or p != 0.96)
 {
 valmod = analogRead(A5);
 valldr = analogRead(A4);
 setpoint = 10;//(1023 - (p2 * 1023)) / 1023;

 if(valmod < (setpoint * 0.9))p = p - 0.02;
 if(valmod > (setpoint * 1.1) && valldr > (setpoint * 1.1))p = p + 0.02;
 delay(1000);
 Serial.println(valmod);
 Serial.println(valldr);
 Serial.println(p);
 }
18
 }
 delay(100);
}
 pinMode(zc,INPUT);
 pinMode(dimmer,OUTPUT);
 attachInterrupt(0, zeroCross, RISING);
 pinMode(LDR,INPUT);
 pinMode(MOD,INPUT);
}
void loop() {
funcao = 0;
if(funcao == 0){
setpoint = 1 - porcentagem;
ms = (setpoint * 8.4);
}
else{
 setpoint = ((1 - porcentagem) * 1023);
 if(analogRead(MOD) < (setpoint - 1023 * 0.05) && ms != 8.4) ms = ms + 1;
 else if(analogRead(MOD) > (setpoint + 1023 * 0.05) && ms != 0) ms = ms - 1;
}
19
delay(1000);
}