### UE5 C++ Synchronous Social Sandbox

# Overview

A server-authoritative multiplayer lobby prototype built in Unreal Engine 5 to demonstrate synchronous networked interactions, client-server state reconciliation, and applied 3D vector math.

This project was built to test custom C++ character controllers and replicate physical interactions across a dedicated Listen Server environment.

# Key Features

- Server-Authoritative Architecture: Custom C++ implementation of Server RPCs (Remote Procedure Calls) to validate client inputs and prevent local manipulation.

- 3D Vector Math Integration: Utilizes dot products and local rotational matrices (GetActorForwardVector) to calculate and apply physical push forces dynamically based on player orientation.

- Synchronous State Replication: Leverages UE5's built-in networking framework to replicate character states and math validations synchronously across multiple connected clients.

# Tech Stack

- Engine: Unreal Engine 5.4

- Language: C++

- Networking: UE5 Listen Server / RPCs
