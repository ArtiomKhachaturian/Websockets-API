# Websockets-API

**Websockets-API** is a lightweight C++ interface definition library for WebSocket-based communication.  
It provides a clean abstraction layer over WebSocket connections, making it easier to integrate different WebSocket client or server implementations under a unified API.

## Features

- Abstract C++ interfaces for WebSocket clients
- Separation of concerns between connection logic and application logic
- Designed for extensibility and portability
- Can be used to decouple WebSocket logic from business logic in larger systems
- Header-only, with no implementation dependencies

## Primary components

- [`EndPoint`](https://github.com/ArtiomKhachaturian/Websockets-API/blob/main/include/WebsocketEndPoint.h) — abstract interface for webSocket client's endpoint
- [`Factory`](https://github.com/ArtiomKhachaturian/Websockets-API/blob/main/include/WebsocketFactory.h) — factory class for creating websocket endpoints
- [`Listener`](https://github.com/ArtiomKhachaturian/Websockets-API/blob/main/include/WebsocketListener.h) — callback-based message and event handler interface
- [`Tls`](https://github.com/ArtiomKhachaturian/Websockets-API/blob/main/include/WebsocketTls.h) — configuration for TLS (Transport Layer Security) settings

## Use Cases

- Building portable WebSocket clients/servers with interchangeable implementations
- Clean architecture separation between WebSocket transport and application code
- Mocking WebSocket communication in unit tests

## License

This project is licensed under the Apache License 2.0.  
See the [LICENSE](LICENSE) file for more information.

## Author

[Artiom Khachaturian](https://github.com/ArtiomKhachaturian)
