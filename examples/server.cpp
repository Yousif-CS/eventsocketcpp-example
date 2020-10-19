#include "eventsocketcpp/server/CustomWebSocket.h"
#include "eventsocketcpp/server/ListeningServer.h"
#include "eventsocketcpp/EventSocket.h"

#include "boost/asio.hpp"

int main(){

    // Initialize the server to listen on the localhost, port 3000
    RedBack::ListeningServer server{"localhost", 3000};

    // Keep accepting connections; the default websocket receive
    // callback is to echo back the message, we can override that however
    
    std::vector<std::shared_ptr<RedBack::WebSocket<boost::asio::ip::tcp::socket>>> websockets;
    while (true){
        auto websocket = server.accept();
        websocket->set_on_receive([websocket](std::string payload) {
            websocket->send("Hello from the example server! Your message: " + payload);
        });
        websockets.push_back(websocket->getPtr());
        RedBack::EventSocket<RedBack::WebSocket<boost::asio::ip::tcp::socket>> es{*websocket};
        es.emit_event("Connect", "Hello from the server!");
    }
}
