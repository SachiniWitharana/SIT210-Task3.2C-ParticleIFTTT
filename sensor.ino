//Terrarium task 3.2C 221216052

int led_pinA         =  A4;
int in_built         =  D7;
int photo_transistor =  A3;
int analog_out_value;

void setup() {

    pinMode(led_pinA , OUTPUT); // output on the LED (has sunlight/ no sunlight)
    pinMode(in_built, OUTPUT);
    pinMode(photo_transistor, INPUT);

}

void loop() {

    analog_out_value = analogRead(photo_transistor); // reading light value in analog
    
    if( analog_out_value > 20 ){ // if less than 15
        //Terrace has sunlight
        Particle.publish("sunlight_hit", "Sunlight"); 
        digitalWrite(led_pinA, LOW);
        digitalWrite(in_built, LOW);
        delay(1200000);
        
    }else{
        //sunlight has stopped
        Particle.publish("sunlight_stopped", "Stopped");
        digitalWrite(led_pinA, HIGH);
        digitalWrite(in_built, HIGH);
        delay(1200000);
    }
}