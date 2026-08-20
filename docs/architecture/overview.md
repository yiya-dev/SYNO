# Architecture Overview

SYNO is planned as a set of layers with minimal coupling.

```text
┌────────────────────────────────────────────────────┐
│                    SYNO UI                         │
├────────────────────────────────────────────────────┤
│          DAW / Editing / Mixer / Workflow         │
├────────────────────────────────────────────────────┤
│              Project / State Model                │
├────────────────────────────────────────────────────┤
│     Sync / Storage Abstraction / Device Model     │
├────────────────────────────────────────────────────┤
│       Audio Engine / MIDI / Plugin Hosting        │
├────────────────────────────────────────────────────┤
│           Platform / Audio Device Layer           │
└────────────────────────────────────────────────────┘
```

The project model should be usable by desktop and future web clients. Server components must not require the desktop UI.

## Key separation

- **Runtime:** executes audio/MIDI and renders the UI.
- **Project model:** describes what a project is.
- **Persistence:** reads/writes project data.
- **Sync:** transfers project changes between mirrors.
- **Server:** authenticates and stores remote state.
- **Web client:** future alternate UI/runtime.
