#define BUTTON 22
#define BUZZER 23

#define C 1047
#define CS 1109
#define D 1175
#define Eb 1245
#define E 1319
#define F 1397
#define FS 1480
#define G 1568
#define Gs 1661
#define A 1760
#define Bb 1865
#define B 1976

hw_timer_t *timer = NULL;

bool buttonPressed = false;
volatile int tempoIndex = 2;
const float tempo[] = {0.25, 0.5, 1, 2, 4}; 

void IRAM_ATTR speedSetting() {
  if (!buttonPressed && digitalRead(BUTTON)==HIGH) {
    buttonPressed = true;
  }
}

void IRAM_ATTR onTimer() {
  digitalWrite(BUZZER, !digitalRead(BUZZER));
}

void play_note(int note, double duration) {
   if (buttonPressed) {
    if (digitalRead(BUTTON) == LOW) {
      tempoIndex = (tempoIndex + 1) % 5; 
      Serial.println(tempoIndex);
    }
    buttonPressed = false;
  }
  int half_period = 500000 / note;
  timerAlarmWrite(timer, half_period, true);
  timerAlarmEnable(timer);
  delay(duration * tempo[tempoIndex]);
  timerAlarmDisable(timer);
}

void play_delay(int duration) {
  digitalWrite(BUZZER, LOW);
  delay(duration);
}

void setup() {
  pinMode(BUTTON, INPUT);
  attachInterrupt(BUTTON, speedSetting, RISING);

  pinMode(BUZZER, OUTPUT);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
}

void loop() {
  play_note(E, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(200);
  play_note(C, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(50);
  play_note(E, 200);
  play_delay(200);
  play_note(E, 200);
  play_delay(200);
  play_note(E, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(200);
  play_note(E, 200);
  play_delay(200);
  play_note(G, 200);
  play_delay(200);
  play_note(G, 200);
  play_delay(200);

  digitalWrite(BUZZER, LOW);
  delay(1000);
  
  play_note(E, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(200);
  play_note(C, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(50);
  play_note(E, 200);
  play_delay(200);
  play_note(E, 200);
  play_delay(200);
  play_note(E, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(200);
  play_note(D, 200);
  play_delay(200);
  play_note(E, 200);
  play_delay(200);
  play_note(G, 200);
  play_delay(200);
  play_note(G, 200);
  play_delay(200);

  digitalWrite(BUZZER, LOW);
  delay(1000);
}