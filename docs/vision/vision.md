# SYNO Vision

SYNO aims to become a music production platform where the **project is the persistent entity** and the DAW runtime is an interface to that project.

A project can run locally, be mirrored to a private server, be mirrored to SYNO Cloud, and eventually be opened from a browser.

The core idea is:

```text
                   SYNO PROJECT
                        │
          ┌─────────────┼─────────────┐
          │             │             │
      Local DAW   Private Server   SYNO Cloud
          │             │             │
          └─────────────┼─────────────┘
                        │
                  Future Web DAW
```

The local and remote representations should use the same logical project model. The implementation should therefore separate:

- the project/data model;
- the real-time audio engine;
- platform-specific UI/device code;
- synchronization and transport;
- server-side persistence.

This separation is a founding architectural principle.
