
#define segment_a 3
#define segment_b 4
#define segment_c 5
#define segment_d 6
#define segment_e 7
#define segment_f 8
#define segment_g 9

#define sink_1 10
#define sink_2 11
#define sink_3 12
#define sink_4 13
int digit;

byte segmentPin [] = {segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g};

byte segmentpattern [] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};



void setup(){
 pinMode(sink_1, OUTPUT);
 pinMode(sink_2, OUTPUT);
 pinMode(sink_3, OUTPUT);
 pinMode(sink_4, OUTPUT);
 pinMode(segment_a, OUTPUT);
 pinMode(segment_b, OUTPUT);
 pinMode(segment_c, OUTPUT);
 pinMode(segment_d, OUTPUT);
 pinMode(segment_e, OUTPUT);
 pinMode(segment_f, OUTPUT);
 pinMode(segment_g, OUTPUT);

 for(int i=0; i<10000; i++){
  for(int j=0; j<1; j++){
  digit = (i/1000);
  digitalWrite(sink_1, LOW);
  digitalWrite(sink_2, HIGH);
  digitalWrite(sink_3, HIGH);
  digitalWrite(sink_4, HIGH);
  setSegment(digit);
  delay(5);
  
  digit = (i/100)%10;
  digitalWrite(sink_1, HIGH);
  digitalWrite(sink_2, LOW);
  digitalWrite(sink_3, HIGH);
  digitalWrite(sink_4, HIGH);
  setSegment(digit);
  delay(5);
  
  digit =(i / 10)%10;
  digitalWrite(sink_1, HIGH);
  digitalWrite(sink_2, HIGH);
  digitalWrite(sink_3, LOW);
  digitalWrite(sink_4, HIGH);
  setSegment(digit);
  delay(5);

  digit = i % 10;
  digitalWrite(sink_1, HIGH);
  digitalWrite(sink_2, HIGH);
  digitalWrite(sink_3, HIGH);
  digitalWrite(sink_4, LOW);
  setSegment(digit);
  delay(5);
  
 Serial.begin(9600);
 
}
 }
}


void loop(){
  int sensorValue = analogRead(A0);
  sensorValue = map(sensorValue, 0, 1023, 0,9999);
  Serial.println(sensorValue);
  
  for(int j=0; j<50; j++){
    digit = (sensorValue / 1000);
    digitalWrite(sink_1, LOW);
    digitalWrite(sink_2, HIGH);
    digitalWrite(sink_3, HIGH);
    digitalWrite(sink_4, HIGH);
    setSegment(digit);
    delay(2);
    
    digit = (sensorValue / 100)%10;
    digitalWrite(sink_1, HIGH);
    digitalWrite(sink_2, LOW);
    digitalWrite(sink_3, HIGH);
    digitalWrite(sink_4, HIGH);
    setSegment(digit);
    delay(2);
    
    digit = (sensorValue / 10) % 10;
    digitalWrite(sink_1, HIGH);
    digitalWrite(sink_2, HIGH);
    digitalWrite(sink_3, LOW);
    digitalWrite(sink_4, HIGH);
    setSegment(digit);
    delay(2);
    
    digit = (sensorValue % 10);
    digitalWrite(sink_1, HIGH);
    digitalWrite(sink_2, HIGH);
    digitalWrite(sink_3, HIGH);
    digitalWrite(sink_4, LOW);
    setSegment(digit);
    delay(2);
}
}

 void setSegment(byte digit){
  byte mask = 1;
  for(int i=0; i<8; i++){
    if((segmentpattern[digit] & mask) == 0) digitalWrite(segmentPin[i], LOW);
    else digitalWrite(segmentPin[i], HIGH);
    mask = mask<<1;
  }
 }
