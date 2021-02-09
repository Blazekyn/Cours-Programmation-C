using System;

namespace RedacttionDesFonctions_Exo
{
    public class Customer
    {
        private string firstName;
        private string lastName;
    }

    public class IndividualCustomer : Customer
    {

    }

    public class CompanyCustomer : Customer
    {

    }

    public abstract class Account
    {
        private Customer customer;
        private double balance;
        private double interestRate;

        public Customer Customer { get; private set; }
        public double Balance { get; private set; }
        public double InterestRate { get; private set; }

        public Account(Customer customer, double balance, double interestRate)
        {
            this.Customer = customer;
            this.Balance = balance;
            this.InterestRate = interestRate;
        }

        public abstract double CalculateInterestAmount(int numberOfMonths);
        public virtual double Deposit(double amount)
        {
            return this.Balance + amount;
        }
    }

    public class LoanAccount : Account
    {

        public LoanAccount(Customer customer, double balance, double interestRate) : base(customer, balance, interestRate) { }

        public override double CalculateInterestAmount(int numberOfMonths)
        {
            double interest = 0.0;

            if (this.Customer is IndividualCustomer)
            {
                if (numberOfMonths > 3)
                {
                    interest = (numberOfMonths - 3) * this.InterestRate;
                }
                else
                {
                    interest = 0.0;
                }

            }

            if (this.Customer is CompanyCustomer)
            {
                if (numberOfMonths > 2)
                {
                    interest = (numberOfMonths - 2) * this.InterestRate;
                }
                else
                {
                    interest = 0.0;
                }
            }

            return interest;
        }
    }
}
