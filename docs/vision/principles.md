# SYNO Principles

## Local-first

A creator must be able to open and edit a project offline.

## Persistent project identity

A project receives a stable identity independent of the machine where it is opened.

## Mirror architecture

A remote copy is a synchronized mirror of the same logical project, with versions and conflict handling.

## User ownership

The cloud should never be the only place where the project exists. Export, local storage and self-hosting must remain viable.

## Graceful degradation

A missing external plugin must not destroy the project. SYNO should retain plugin identifiers/state and allow recovery or rendered/frozen audio where available.

## Reproducibility

Projects record enough metadata to explain which plugins, versions, samples and settings they depended on.

## Web compatibility

The project format and core data model should not assume that every execution target is a native desktop process.

## Native differentiation

SYNO Native instruments/effects can provide tighter integration, deterministic state serialization and better portability than third-party plugins.

## Hardware independence

SynthOrdi is a first-party hardware target, not a prerequisite for SYNO.
