#include <stdio.h>
#include <pthread.h>

int account_money;
pthread_mutex_t account_lock;

void* withdraw(void* arg) {
	int id = (int)arg;
	int money = 1000;
	int transactions;

	for(transactions = 0; transactions < 20; transactions++) {
		if(pthread_mutex_lock(&account_lock) < 0)
			perror("Mutex lock error");

		if(account_money < 50) {
			printf("Not enough money in bank account\n");
		} else {
			money += 50;
			account_money -= 50;
			sleep(1);
		}

		if(pthread_mutex_unlock(&account_lock) < 0)
			perror("Mutex unlock error");

		printf("Banker %d withdraw $50 from bank account\n", id);
		// Take break
		sleep(1);
	}

	printf("Banker %d: %d money remaining\n", id, money);
}

void* deposit(void* arg) {
	int id = (int)arg;
	int money = 1000;
	int transactions;

	for(transactions = 0; transactions < 20; transactions++) {
		if(pthread_mutex_lock(&account_lock) < 0)
			perror("Mutex lock error");

		if(money < 50) {
			printf("Not enough money in bankers accout\n");
		} else {
			money -= 50;
			account_money += 50;
			sleep(1);
		}

		if(pthread_mutex_unlock(&account_lock) < 0)
			perror("Mutex unlock error");

		printf("Banker %d deposited $50 from bank account\n", id);
		// Take break
		sleep(1);
	}

	printf("Banker %d: %d money remaining\n", id, money);
}

int main(int argc, char** argv) {
	int bankers_count = 2;

	if(argc > 1)
		bankers_count = atoi(argv[1]);

	account_money = 5000;
	pthread_t bankers[bankers_count];

	if(pthread_mutex_init(&account_lock, NULL) < 0)
		perror("Mutex init error");

	int i;
	for(i = 0; i < bankers_count; i++) {
		if(i < bankers_count / 2)
			if(pthread_create(&bankers[i], NULL, withdraw, (void*)i) < 0)
				perror("Thread create error");
		else
			if(pthread_create(&bankers[i], NULL, deposit, (void*)i) < 0)
				perror("Thread create error");
	}

	for(i = 0; i < bankers_count; i++)
		if(pthread_join(bankers[i], NULL) < 0)
			perror("Thread join error");

	if(pthread_mutex_destroy(&account_lock) < 0)
		perror("Mutex destroy error");

	printf("%d money remaining in bank acount\n", account_money);

	return 0;
}