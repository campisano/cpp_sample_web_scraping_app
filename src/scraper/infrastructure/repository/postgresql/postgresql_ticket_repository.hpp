#ifndef POSTGRESQL_TICKET_REPOSITORY__HPP__
#define POSTGRESQL_TICKET_REPOSITORY__HPP__

#include "postgresql_source.hpp"
#include "../../../domain/repositories/ticket_repository.hpp"

class PostgresqlTicketRepository : public TicketRepository
{
public:
    explicit PostgresqlTicketRepository(PostgresqlSource & _db);
    PostgresqlTicketRepository(const PostgresqlTicketRepository &) = delete;
    PostgresqlTicketRepository(PostgresqlTicketRepository &&) = delete;
    virtual ~PostgresqlTicketRepository();

    PostgresqlTicketRepository & operator=(
        const PostgresqlTicketRepository &) = delete;
    PostgresqlTicketRepository & operator=(
        PostgresqlTicketRepository &&) = delete;

public:
    virtual void insert(const Ticket & _ticket);
    virtual std::vector<Ticket> getAll();

private:
    PostgresqlSource & m_db;
};

#endif
