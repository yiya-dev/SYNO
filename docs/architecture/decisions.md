# Architecture Decision Log

## 2026-08-20 — Repository structure

Decision: Keep the initial ecosystem in one repository, `yiya-dev/SYNO`, while components remain early-stage.

Reason: SYNO is still being defined. One repository provides a single vision, shared documentation and a unified history. Components may be split later if scale requires it.

## 2026-08-20 — Desktop technology direction

Decision: C++ + JUCE + CMake for the native DAW core.

Reason: Real-time audio, MIDI, plugin hosting and native desktop performance are primary requirements.

## 2026-08-20 — Server technology direction

Decision: Python is a strong initial candidate for server/backend/tools.

Reason: Rapid development, networking/API ecosystem and suitability for non-real-time services.

## 2026-08-20 — Local-first / mirror model

Decision: Cloud and self-hosted storage are mirrors of a logical project rather than the only authoritative copy.

Reason: Offline use, resilience, self-hosting and future multi-device/web support.

## 2026-08-20 — Web DAW direction

Decision: Design the project model for browser use from the beginning.

Reason: Avoid rebuilding project storage and synchronization architecture later.
