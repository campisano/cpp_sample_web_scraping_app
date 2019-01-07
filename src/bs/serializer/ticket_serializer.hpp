#ifndef TICKET_SERIALIZER__HPP__
#define TICKET_SERIALIZER__HPP__

#include <json.hpp>
#include <string>

#include "../domain/ticket.hpp"

namespace nlohmann
{
    template <>
    struct adl_serializer<Ticket>
    {
        static void to_json(json & _data, const Ticket & _ticket)
        {
            _data = json{
                {"high", _ticket.high()},
                {"last", _ticket.last()},
                {"timestamp", _ticket.timestamp()},
                {"bid", _ticket.bid()},
                {"vwap", _ticket.vwap()},
                {"volume", _ticket.volume()},
                {"low", _ticket.low()},
                {"ask", _ticket.ask()},
                {"open", _ticket.open()}
            };
        }

        static Ticket from_json(const json & _data)
        {
            return Ticket{
                static_cast<long>(std::stod(_data["high"].get<std::string>()) * 100),
                    static_cast<long>(std::stod(_data["last"].get<std::string>()) * 100),
                    static_cast<long>(std::stod(_data["timestamp"].get<std::string>())),
                    static_cast<long>(std::stod(_data["bid"].get<std::string>()) * 100),
                    static_cast<long>(std::stod(_data["vwap"].get<std::string>()) * 100),
                    static_cast<long>(std::stod(_data["volume"].get<std::string>()) * 100),
                    static_cast<long>(std::stod(_data["low"].get<std::string>()) * 100),
                    static_cast<long>(std::stod(_data["ask"].get<std::string>()) * 100),
                    static_cast<long>(_data["open"].get<double>() * 100)
                    };
        }
    };
}

#endif
