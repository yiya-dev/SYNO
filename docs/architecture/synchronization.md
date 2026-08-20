# Synchronization and Project Mirroring

SYNC is not only backup. SYNO should treat remote copies as **mirrors of a logical project**.

## Model

```text
             Project ID: ABC123
                     │
        ┌────────────┼────────────┐
        ▼            ▼            ▼
   Desktop A    Private Server   Cloud
        │            │            │
        └────────────┼────────────┘
                     ▼
                 Web Client
```

Each mirror has local metadata describing:

- project ID
- mirror/device ID
- last known version
- pending local changes
- sync state

## Important requirements

- offline edits are allowed;
- uploads are incremental where practical;
- interrupted transfers resume;
- conflicts are detected, not silently overwritten;
- versions/snapshots remain recoverable;
- deletion should support recovery/retention policies;
- audio can be transferred separately from small metadata changes.

## Source of truth

The architecture should avoid permanently privileging one physical machine as the only source of truth. The logical project identity is authoritative; replicas synchronize toward a consistent versioned state.
