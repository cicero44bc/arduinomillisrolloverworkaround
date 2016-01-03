/*

Arduino millis() rollover workaround example.

Calculates the duration in millis between two millis values and returns the correct value even if millis() rolls over.

This is useful when creating tasks that need to run for a durations that cannot be affected by millis() rolling over.

*/

void setup() {
  Serial.begin(9600);  
}

void loop() {
//Test Runs
Serial.println("After rollover: " + String(getDuration(4294967286,10))); // Returned value should be 20ms.
Serial.println("Before rollover: " + String(getDuration(10,40))); // Returned value should be 30ms.
}

unsigned long getDuration(unsigned long timeStart, unsigned long timeFinish)
{
  unsigned long duration;

  Serial.println("timeFinish: " + String(timeFinish));
  Serial.println("timeStart: " + String(timeStart));
  if(timeFinish < timeStart)
  {
    duration = ((4294967296 - timeStart)+(timeFinish)); // Max value of unsigned is 4294967296.
    return duration;
  }
  else
  {
    duration = timeFinish - timeStart;
    return duration;
  }
}
