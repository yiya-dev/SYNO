# `.syno` Project Format

The `.syno` format is a long-term strategic component of SYNO.

A logical project contains:

- stable project ID
- project metadata
- tracks
- clips
- MIDI
- automation
- routing
- plugin instances and plugin state
- audio files
- samples/references
- presets
- version metadata
- compatibility metadata

Conceptual layout:

```text
MySong.syno/
├── project.json
├── tracks/
├── midi/
├── automation/
├── plugins/
├── audio/
├── samples/
├── presets/
└── metadata.json
```

The physical representation may evolve. The logical model must remain versioned and migratable.

## Design goals

- deterministic serialization where practical;
- backward compatibility;
- migration tooling;
- human-inspectable metadata;
- binary/audio content stored efficiently;
- no dependency on a specific cloud provider.
