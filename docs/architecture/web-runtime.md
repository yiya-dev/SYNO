# Web Runtime Architecture

The web target should be treated as a first-class architectural target without forcing the native runtime to become a browser app immediately.

Potential layers:

```text
Shared project model
        │
        ├── Native runtime
        │      └── desktop audio/device APIs
        │
        └── Web runtime
               └── browser audio/device APIs
```

The shared layer should prioritize data structures, serialization, scheduling concepts and deterministic state handling.
