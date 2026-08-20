# Plugin System

SYNO supports two broad plugin families:

## External plugins

Third-party VST3 plugins installed on the host machine.

The project stores enough information to identify the dependency:

- manufacturer
- plugin name
- format
- unique identifier
- version when available
- state data
- preset information when relevant

Missing plugins must not make the project unrecoverable.

## SYNO Native

First-party instruments/effects are designed specifically for the SYNO project model. Native plugins can provide highly portable state and tighter integration with the future web and SynthOrdi targets.
