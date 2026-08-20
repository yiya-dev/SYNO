# Security Architecture

Security is part of the initial design because SYNO will eventually handle private creative projects and potentially accounts.

## Principles

- TLS for network traffic
- short-lived access tokens where appropriate
- refresh/revocation strategy
- least-privilege device access
- encrypted secrets at rest where practical
- no credentials inside Git
- no production secrets in local configuration files committed to the repository
- audit-friendly server events

## Private server

Self-hosted users should control their own domains, certificates, storage and retention policies.
