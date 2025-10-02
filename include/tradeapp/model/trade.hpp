
class Trade
{
private:
public:
    const long id;
    const int timestamp;
    const long sellerId;
    const long buyerId;
    const long amount;
    const long quantity;

    Trade(long id, int timestamp, long sellerId, long buyerId, long amount, long quantity);
};
