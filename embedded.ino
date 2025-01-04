int pin_out = 7;
int dit = 250;
int inter_ele = 250;
int dah = 750;
int inter_letter = 750;
int inter_word = 1750;


void setup(){
  pinMode(pin_out, OUTPUT);
}

void loop(){

  digitalWrite(pin_out, HIGH);
  delay(dit);
  digitalWrite(pin_out, LOW);
  delay(inter_ele);
  digitalWrite(pin_out, HIGH);
  delay(dit);
  digitalWrite(pin_out, LOW);
  delay(inter_ele);
  digitalWrite(pin_out, HIGH);
  delay(dit);
  digitalWrite(pin_out, LOW);
  delay(inter_letter);

  digitalWrite(pin_out, HIGH);
  delay(dah);
  digitalWrite(pin_out, LOW);
  delay(inter_ele);
  digitalWrite(pin_out, HIGH);
  delay(dah);
  digitalWrite(pin_out, LOW);
  delay(inter_ele);
  digitalWrite(pin_out, HIGH);
  delay(dah);
  digitalWrite(pin_out, LOW);
  delay(inter_letter);

  digitalWrite(pin_out, HIGH);
  delay(dit);
  digitalWrite(pin_out, LOW);
  delay(inter_ele);
  digitalWrite(pin_out, HIGH);
  delay(dit);
  digitalWrite(pin_out, LOW);
  delay(inter_ele);
  digitalWrite(pin_out, HIGH);
  delay(dit);
  digitalWrite(pin_out, LOW);
  delay(inter_word);

}
