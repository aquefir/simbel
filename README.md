# Simbel

_A static site generator written in ANSI C._

Created by Alexander Nicholi.

Copyright &copy; 2022 Aquefir. All rights reserved  
Released under Artisan Software Licence v1.1

Usage:

```
simbel <-h|--help|-?>
simbel [flags] <config.ini> [input dir] [output dir]
```

The first usage shows this help output, and exits.

The second usage runs the program to generate a static website. If the input dir or the output dir are not given, they both default to `$PWD`. These are the flags available for this usage:

Flag                          | Description
------------------------------|------------------------------------------------
`-f`, `--force-strict`        | Force all endpoints to be strict, regardless of the given setting in the config file.
`-i <name>`, `--index <name>` | Set the name of the output file for the root endpoint. defaults to `index.html`.
`-l`, `--force-lax`           | Force all endpoints to be lax, regardless of the given setting in the config file.
`-s`, `--symlink`             | Use symbolic links for lax endpoints (the default).
`-c`, `--copy`                | Make physical copies of pages for lax endpoints. This is the inverse of --symlink.
`-q`, `--quiet`               | Silence all streaming to `std{out,err}`.

In endpoint configurations, "strict" means that URLs without a trailing slash will not be duplicated or symlinked into an additional "endpoint" that is the same but with a trailing slash, for example `GET /foo/` will not return the same data as `GET /foo` when the endpoint is strict. Likewise, "lax" means the inverse of strict: with a lax endpoint, `GET /foo/` will return the same data as `GET /foo`. Simbel will attempt to detect erroneous configurations bearing endpoint conflicts, e.g. if a lax endpoint has implicated another explicit endpoint that matches its variant.

Simbel will never output any diagnostic or logging information to `stdout`. All such data is streamed to `stderr`, and this too can be prevented with the `--quiet` flag.
