# LUNA (Local User Network Analyzer)

LUNA is a lightweight, high-performance local network sniffing and user traffic analysis utility written in modern C++. Built with a strict focus on minimalism and real-time network auditing, it monitors local interfaces, tracks data packets, and yields structural analytics directly to the terminal.

## Features
- **Packet Traffic Mapping:** Simulates and monitors network packet flow on local interfaces.
- **Active User Tracking:** Identifies and logs behavior vectors of active local hosts.
- **Zero Heavy Dependencies:** Written entirely in pure, native C++ for extreme portability.
- **Clean Architecture:** Fully written with explicit Allman-style formatting and encapsulated within custom namespaces.

## Usage
Run the executable with an optional argument specifying the network interface (e.g., eth0, wlan0) to monitor:
```bash
./luna wlan0
```

## Architecture & Style
LUNA strictly follows the **KISS** (Keep It Simple, Stupid) principle and is optimized for low memory usage. The codebase uses the Allman style for bracket alignment, ensuring high readability and seamless minification for single-line deployment architectures.

## License
This project is open-source and licensed under the **GNU GPL v3.0**. See the LICENSE file for details. All rights reserved by **hypernova-developer**.
