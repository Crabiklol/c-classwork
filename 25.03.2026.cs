interface IPaymentMethod
{
    bool Pay(decimal amount);
}

public class CardPayment : IPaymentMethod
{
        public bool Pay(decimal amount)
    {
        Console.WriteLine($"Оплата картой прошла успешно на сумму {amount} рублей. ");
        return true;
    }
}

public class CryptoPayment : IPaymentMethod
{
    public bool Pay(decimal amount) 
    {
        Console.WriteLine($"Транзакция в блокчейне подтверждена на сумму {amount} рублей. ");
        return true;
    }
}

class Programm
{
    static void Main()
    {
        IPaymentMethod card = new CardPayment();
        IPaymentMethod crypto = new CryptoPayment();

        card.Pay(100);
        crypto.Pay(100);
    }
}
