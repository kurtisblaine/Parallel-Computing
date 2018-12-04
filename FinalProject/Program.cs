using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace FinalProject
{
    class Program
    {
        
        static void Main(string[] args)
        {
            //Function to call how to create a task in C#
            //TasksReturnsValues();


            //Functiona to call Mutex Example
            // MutexBankApp();

            ManualEvent();
            AutomaticEvent();
            Console.ReadKey();
            Console.ReadLine();
        }

        #region Creates Task in C#
        public static int TextLength(object o)
        {
            Console.WriteLine($"\nThread with id {Task.CurrentId} cooking food '{o}'...");
            return o.ToString().Length;
        }

        private static void TasksReturnsValues()
        {
            string text1 = "Breakfast Tacos", text2 = "Pizza";
            var task1 = new Task<int>(TextLength, text1);
            task1.Start();
            var task2 = Task.Factory.StartNew(TextLength, text2);
          
            Console.WriteLine($"\nPrice of '{text1}' is $" + task1.Result.ToString().Length);
            Console.WriteLine($"\nPrice of '{text2}' is ${task2.Result}.");
        }
        #endregion

        #region Mutex Example in C#
        class BankAccount
        {
            public int Balance { get; private set; }

            public BankAccount(int balance)
            {
                Balance = balance;
            }

            public void Deposit(int amount)
            {
                Balance += amount;
            }

            public void Withdraw(int amount)
            {
                Balance -= amount;
            }

            public void Transfer(BankAccount where, int amount)
            {
                where.Balance += amount;
                Balance -= amount;
            }
        }

        public static void MutexBankApp()
        {
            var tasks = new List<Task>();
            var CheckingAccount = new BankAccount(0);
            var SavingsAccount = new BankAccount(0);

            Mutex MutexPersonDeposits = new Mutex();
            Mutex MutexPersonSaves = new Mutex();

            
                tasks.Add(Task.Factory.StartNew(() =>
                {
                    for (int j = 1; j <= 5; ++j)
                    {
                       // Console.WriteLine("Starts Mutex to Make Deposit Into Checking Account");
                       bool Lock = MutexPersonDeposits.WaitOne();
                     
                        try
                        {
                            Console.WriteLine("Depositing to Checking Account $" + j * 100);
                            CheckingAccount.Deposit(j * 1500); 
                        }
                        finally
                        {
                            if (Lock) MutexPersonDeposits.ReleaseMutex();
                            //Console.WriteLine("Releases Mutex After Deposit");
                        }
                    }
                }));

                tasks.Add(Task.Factory.StartNew(() =>
                {
                    for (int j = 1; j <= 5; ++j)
                    {
                        bool Lock = MutexPersonSaves.WaitOne();
                        //Console.WriteLine("Starts Mutex to Make Deposito Into Savings Account");
                        try
                        {
                            Console.WriteLine("Depositing to Savings Account $" + j * 1000);
                            SavingsAccount.Deposit(j * 500); // deposit 10000
                        }
                        finally
                        {
                            if (Lock) MutexPersonSaves.ReleaseMutex();
                            //Console.WriteLine("Releases Mutex After Depositing to Savings Account\n");
                        }
                    }
                }));

                //Locking Checking And Savings Account to be able to make transfer of money
                tasks.Add(Task.Factory.StartNew(() =>
                {
                    for (int j = 1; j <= 10; j++)
                    {
                        bool Lock = Mutex.WaitAll(new[] { MutexPersonDeposits, MutexPersonSaves });

                        try
                        {
                            Console.WriteLine("Transfer from savings to checking amount of $" + (j * 500) / 3);
                            CheckingAccount.Transfer(SavingsAccount, (j*500)/6); //Makes Transfers
                        }
                        finally
                        {
                            if (Lock)
                            {
                                MutexPersonDeposits.ReleaseMutex();
                                MutexPersonSaves.ReleaseMutex();
                            }
                        }
                    }
                }));
            

            Task.WaitAll(tasks.ToArray());

            Console.WriteLine($"\nChecking Account Balance $ ={CheckingAccount.Balance}, \nSavings Account Balance ${SavingsAccount.Balance}.");
        }


        #endregion


        #region ManualResetEventslim and AutoResetEvent Examples

        public static void ManualEvent()
        {
            var Event = new ManualResetEventSlim();
            var CancelEvent = new CancellationTokenSource();
            var Token = CancelEvent.Token;

            Task.Factory.StartNew(() =>
            {
                Console.WriteLine("Pulling the trigger");
                for (int i = 1; i <= 30; i++)
                {
                    Token.ThrowIfCancellationRequested();
                    Console.WriteLine("Shooting round " + i);
                    Thread.Sleep(100);
                    
                }
                Console.WriteLine("Reloading AR-15");
                Event.Set();
            }, Token);

            var ReLoading = Task.Factory.StartNew(() =>
            {
                Console.WriteLine("Loading AR-15");
                Event.Wait(5000, Token);
                Console.WriteLine("Loading Magazine");
               
                Event.Reset();
                Event.Wait(1000, Token); 
                Console.WriteLine("AR-15 Is Ready...");
            }, Token);

            ReLoading.Wait(Token);
        }


        private static void AutomaticEvent()
        {
            var Event = new ManualResetEvent(false);
            //var Event = new AutoResetEvent(true);

            Event.Set();

            Event.WaitOne(); 

            if (Event.WaitOne(1000))
            {
                Console.WriteLine("Nice Shooting!");
            }
            else
            {
                Console.WriteLine("You suck!");
            }
        }
        #endregion


    }

}
