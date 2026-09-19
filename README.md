# NosBoost SDK

This repo holds the class and packet definitions for the NosTale client. It is not a program by itself. It is a library that other parts of NosBoost use.

## What is inside

- `classes/` — the layout of important game objects, like widgets (buttons, labels, panels, gauges). These match the exact memory layout the real game uses, so code built with these definitions can read and change the game's real objects safely.
- `packets/` — the layout of network packets sent between the game and the server. These let code read the data inside a packet instead of just seeing raw bytes.

## Who uses this repo

You will almost never open this repo on its own. It is pulled in automatically by:

- the NosBoost runtime, so it can find and manage widgets and packets, and
- the ModKit repo, so a mod you write can use the same class and packet definitions.

## Why this exists as its own repo

The game's classes and packets do not change often. Keeping them in one shared place means the runtime and every mod always agree on the same layout. If this ever gets out of sync with the real game, expect crashes, since the layout must match the game's memory exactly.
