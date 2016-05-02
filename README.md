# arduinomillisrolloverworkaround

Arduino millis() rollover workaround example.

Calculates the duration in millis between two millis values and returns the correct value even if millis() rolls over.

This is useful when creating tasks that need to run for a durations that cannot be affected by millis() rolling over.

The next thing to add is support for multiple rollovers!
