#include "postgresql_ticket_repository.hpp"

#include <sstream>
#include <sqlpp11/sqlpp11.h>

PostgresqlTicketRepository::PostgresqlTicketRepository(
    PostgresqlSource & _db) : m_db(_db)
{
}

PostgresqlTicketRepository::~PostgresqlTicketRepository()
{
}

void PostgresqlTicketRepository::insert(const Ticket & _ticket)
{
    std::stringstream sql;
    sql << "INSERT INTO ticket ("
        << "timestamp, low, high, last, bid, ask, volume, source"
        << ") VALUES ("
        << _ticket.timestamp() << ", "
        << _ticket.low() << ", "
        << _ticket.high() << ", "
        << _ticket.last() << ", "
        << _ticket.bid() << ", "
        << _ticket.ask() << ", "
        << _ticket.volume() << ", "
        << _ticket.source() << ") RETURNING id;";

    auto statement = sqlpp::custom_query(sqlpp::verbatim(sql.str()))
                     .with_result_type_of(
                         sqlpp::select(sqlpp::value(0).as(sqlpp::alias::a)));

    auto db = m_db.connection();
    auto tx = start_transaction(*db.get());

    for(const auto & row : (*db)(statement))
    {
        std::cout << "ID: " << row.a << std::endl;
    }

    tx.commit();
}

std::vector<Ticket> PostgresqlTicketRepository::getAll()
{
    std::stringstream sql;
    sql << "SELECT"
        << " timestamp, low, high, last, bid, ask, volume, source"
        << " FROM ticket"
        << " ORDER BY timestamp DESC";

    auto statement = sqlpp::custom_query(sqlpp::verbatim(sql.str()))
                     .with_result_type_of(
                         sqlpp::select(
                             sqlpp::value(0).as(sqlpp::alias::a),
                             sqlpp::value(0).as(sqlpp::alias::b),
                             sqlpp::value(0).as(sqlpp::alias::c),
                             sqlpp::value(0).as(sqlpp::alias::d),
                             sqlpp::value(0).as(sqlpp::alias::e),
                             sqlpp::value(0).as(sqlpp::alias::f),
                             sqlpp::value(0).as(sqlpp::alias::g),
                             sqlpp::value(0).as(sqlpp::alias::h)
                         ));

    auto db = m_db.connection();
    auto tx = start_transaction(*db.get());

    std::vector<Ticket> tickets;

    for(const auto & row : (*db)(statement))
    {
        tickets.push_back(
            Ticket(row.a, row.b, row.c, row.d, row.e, row.f, row.g, row.h));
    }

    tx.commit();

    return tickets;
}
