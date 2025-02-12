const int led_red = 5; 
const int led_yellow = 6;  
const int led_green = 7;   
const int push_button = 2; 
bool pedestrian_press = false; 

unsigned long previous_time = 0;        
const long greentime = 5000;            
const long yellowtime = 5000;           
const long redtime = 5000;              
const long red_time_pedestrain = 10000; 

void setup()
{
    pinMode(led_red, OUTPUT);    
    pinMode(led_yellow, OUTPUT); 
    pinMode(led_green, OUTPUT);  
    pinMode(push_button, INPUT); 
}

void loop()
{
    if (digitalRead(push_button) == HIGH) 
    {
        delay(50);                            
        if (digitalRead(push_button) == HIGH) 
        {
            pedestrian_press = true;
        }
    }
    // Pedestrian
    if (pedestrian_press)
    {
        analogWrite(led_red, 255);     
        digitalWrite(led_yellow, LOW); 
        digitalWrite(led_green, LOW);  
        delay(red_time_pedestrain);    
        pedestrian_press = false;     
    }

   
    previous_time = millis(); 
    digitalWrite(led_green, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, LOW);

    while (millis() - previous_time < greentime) 
    {
        if (digitalRead(push_button) == HIGH)
        {
            pedestrian_press = true;
            return;
        }
    }

   
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, HIGH);

    previous_time = millis();
    while (millis() - previous_time < yellowtime)
    {
        if (digitalRead(push_button) == HIGH)
        {
            pedestrian_press = true;
            return; 
        }
    }

    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, HIGH);

    previous_time = millis();
    while (millis() - previous_time < redtime)
    {
        if (digitalRead(push_button) == HIGH)
        {
            pedestrian_press = true;
            return; 
        }
    }
    digitalWrite(led_red, LOW); 
}