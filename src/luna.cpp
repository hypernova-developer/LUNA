#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

namespace bettercpp
{
    class LunaAnalyzer
    {
    private:
        std::string interfaceName;

        void logNetwork(const std::string& tag, const std::string& info)
        {
            std::cout << "[LUNA-NET][" << tag << "] " << info << std::endl;
        }

    public:
        LunaAnalyzer(const std::string& iface)
        {
            interfaceName = iface;
        }

        void startAnalysis()
        {
            std::cout << "==================================================" << std::endl;
            std::cout << " LUNA: Local User Network Analyzer Engine" << std::endl;
            std::cout << "==================================================" << std::endl;

            logNetwork("INIT", "Binding core socket analyzer to interface: " + interfaceName);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            logNetwork("LISTEN", "Promiscuous mode enabled. Sniffing packets...");
            std::this_thread::sleep_for(std::chrono::milliseconds(300));

            std::vector<std::string> mockPackets = {
                "TCP -> 192.168.1.45:443 [HTTPS] - 1420 bytes",
                "UDP -> 192.168.1.12:53 [DNS Query] - 64 bytes",
                "ICMP -> 192.168.1.1:0 [Ping Request] - 32 bytes"
            };

            for (const auto& packet : mockPackets)
            {
                logNetwork("CAPTURE", packet);
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }

            std::cout << "--------------------------------------------------" << std::endl;
            logNetwork("YIELD", "Analysis pipeline paused. Session packets flushed.");
            std::cout << "==================================================" << std::endl;
        }
    };
}

int main(int argc, char* argv[])
{
    std::string targetInterface = "eth0";

    if (argc > 1)
    {
        targetInterface = argv[1];
    }

    bettercpp::LunaAnalyzer analyzer(targetInterface);
    analyzer.startAnalysis();

    return 0;
}
