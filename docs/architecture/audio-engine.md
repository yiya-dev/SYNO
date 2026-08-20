# Audio Engine

Initial target: deterministic, low-latency, real-time safe audio processing.

Planned modules:

- AudioDevice
- AudioBuffer
- AudioGraph
- AudioNode
- AudioThread
- Mixer
- Channel
- Bus
- Master
- Metering
- Latency management

## Real-time rule

No blocking file I/O, allocation-heavy operations or network calls on the real-time audio thread.

Project loading, cloud synchronization, plugin scanning and disk operations must remain outside the audio thread.
