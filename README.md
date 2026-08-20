# SYNO

**SYNO** is a planned digital audio workstation and music software ecosystem built around one core idea: a music project should remain usable, recoverable and synchronized across local computers, private servers, official cloud infrastructure and, eventually, a browser-based DAW.

## Vision

SYNO is not only a traditional desktop DAW. The project is designed from the beginning around a **shared project model** so that the same musical project can have a local runtime and one or more remote mirrors.

The long-term ecosystem is planned as:

- **SYNO DAW** — desktop DAW for Windows/Linux first, with future cross-platform targets.
- **SYNO Server** — self-hosted server for private synchronization and backup.
- **SYNO Cloud** — hosted infrastructure using the same concepts/APIs as the private server.
- **SYNO Web DAW** — future browser client/runtime using the same project model.
- **SYNO Tools** — developer/user utilities for projects, plugins, diagnostics and maintenance.
- **SYNO Native** — first-party instruments and effects integrated deeply into the DAW.
- **SynthOrdi integration** — dedicated hardware designed around SYNO.
- **SYNO Token / ecosystem layer** — optional future economic layer; never required to create or save music.

## Core principles

1. **Project persistence first.** A project should be recoverable even if a computer fails.
2. **Local-first.** SYNO remains fully useful without an internet connection.
3. **Mirror, not just backup.** Remote storage is a synchronized representation of the project, not merely a file dump.
4. **Private-server friendly.** Users should be able to self-host.
5. **Online-ready by design.** The project model and services are designed so a future web DAW can operate on the same project.
6. **Plugin compatibility.** External VST3 plugins remain supported; native SYNO plugins receive deeper integration.
7. **Long-term recoverability.** The `.syno` format should be documented, versioned and migratable.
8. **Hardware is optional.** SYNO must remain a useful standalone DAW; SynthOrdi enhances it rather than defining it.
9. **Crypto is optional.** The SYNO token must never be a prerequisite for using the DAW.

## Initial technology direction

- Desktop DAW: **C++ + JUCE + CMake**
- Server/backend/tools: **Python** where practical
- Development environment: **VS Code**
- Version control: **Git + GitHub**
- Data/storage: pluggable local filesystem + database/object storage concepts
- Future web runtime: browser-compatible core where technically practical, with explicit limitations for third-party native plugins

## Repository map

```text
src/        SYNO desktop application and shared core
server/     Self-hosted SYNO Server
 tools/     SYNO command-line and maintenance tools
build/      Build, packaging and release scripts
tests/      Automated tests
resources/  UI resources and first-party assets
docs/       Vision, architecture and specifications
cmake/      Shared CMake helpers
examples/   Small integration and format examples
```

## Development status

This repository is the initial architecture and planning baseline. The first implementation milestone is a minimal native runtime capable of opening a window, initializing an audio device, producing audio, receiving MIDI and saving a first `.syno` project.

## Project status

The repository is intentionally **private during early development**. Public release, licensing and collaboration policy will be decided later.
