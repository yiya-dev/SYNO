# SYNO Server

Self-hosted reference architecture.

Possible initial stack:

- Python
- FastAPI
- PostgreSQL
- local filesystem or S3-compatible object storage
- HTTPS

Core responsibilities:

- authentication
- device registration
- project metadata
- project storage
- versions/snapshots
- synchronization API
- access control
- health/status

The server must not depend on the desktop UI.
