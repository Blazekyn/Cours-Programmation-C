using System;

namespace RedacttionDesFonctionsSolution
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

        //Abstract template (needs to override)
        public abstract double CalculateInterestAmount();
        
        //Virtual method (optionnal override)
        //Could override this method in Loan account and simply
        //refactor the body of the deposit method to suits our needs.
        public virtual double Deposit(double amount)
        {
            return this.Balance + amount;
        }
    }

    public class LoanAccount : Account
    {
        private int lenghtOfLoan;
        
        //Constrcutor
        //"base" is referring to the original class.
        public LoanAccount(Customer customer, double balance, double interestRate,
                           int lenghtOfLoan) : base(customer, balance, interestRate) { }


        public override double CalculateInterestAmount()
        {
            //double interest = 0.0;

            if (this.Customer is CompanyCustomer)
            {
                return calculateInterest(2);
            }
            else
            {
                return calculateInterest(3);
            }

            //return 0.0;
        }

        public double calculateInterest(int minimumLoanDuration)
        {
            if (lenghtOfLoan > minimumLoanDuration)
            {
                return (lenghtOfLoan - minimumLoanDuration) * this.InterestRate;
            }
            return 0.0;
        }
    }
}
