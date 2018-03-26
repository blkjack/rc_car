void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT);//throttel up
pinMode(5,INPUT);//l or r
Serial.begin(9600);

pinMode(9, OUTPUT); //pwn
pinMode(8,OUTPUT);//dir

 pinMode(12,OUTPUT);//dir
 pinMode(11,OUTPUT);//pwn

}

void loop() {
 
  int ch2=pulseIn(3,HIGH,25000);
  int ch1=pulseIn(5,HIGH,25000);

 Serial.println(ch2);
Serial.println(ch1);
  //delay(500);
          analogWrite(9, 0);
          digitalWrite(8,HIGH);
          analogWrite(11, 0);
          digitalWrite(12,HIGH);
        
  
   if    ((ch2>1730 && ch2<1830) ||(ch2>1150 && ch2<1200))              
        { 
         
              if(ch2>1730 && ch2<1830)              // forwrd
      
        { 
          analogWrite(9, 100);
          digitalWrite(8,HIGH);
          analogWrite(11, 100);
          digitalWrite(12,HIGH);
          
          }
      else if(ch2>1150 && ch2<1200)         //  back
        { 
          analogWrite(11, 100);
          digitalWrite(8,LOW);
           analogWrite(9, 100); 
           digitalWrite(12,LOW);
          
        } 

          

        }

       
        
 else if( (ch1<1100 && ch1>1000)  ||  (ch1>1800 && ch1<1840) )   
        { 
          
          
          
          
         
       if(ch1<1100 && ch1>1000)         // rt
        { analogWrite(11, 250);
          analogWrite(9, 250); 
          digitalWrite(12,LOW);
           digitalWrite(8,HIGH); 
        }  
      else if(ch1>1800 && ch1<1840)       //  lf
        { 
           analogWrite(11, 250);
           analogWrite(9, 250); 
           digitalWrite(8,LOW);
           digitalWrite(12,HIGH); 
        }   
        }

}

