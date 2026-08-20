# Web DAW Direction

The web DAW is a strategic future target, so the architecture should be online-ready from the beginning.

## Goal

A user should eventually be able to open a SYNO project from a browser and work on it without converting the project into a completely different format.

## What this implies

The project model must be independent from native UI code. The sync API and server-side project model must be client-neutral.

The browser client may use a web-compatible build of shared processing code where practical. Features that depend on native OS/plugin facilities need explicit fallback strategies.

## Plugin limitation

Third-party desktop VST3 plugins are native software. They cannot simply be assumed to run in a browser. Therefore the web DAW needs a compatibility model.

Possible future strategies:

- SYNO Native web-compatible instruments/effects;
- rendered/frozen audio for unsupported plugins;
- server-side rendering for selected workloads;
- project feature compatibility warnings;
- browser-only editing for projects containing unsupported native plugins.

The web DAW should not compromise the native DAW's plugin ecosystem.
