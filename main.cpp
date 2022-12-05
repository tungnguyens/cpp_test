#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

class thread_data_t {
  int thread_id;
  char message[100];

public:
  thread_data_t(int id = 0, const char *msg = "msg_id") {
    thread_id = id;
    if (strlen(msg) < 100) {
      memcpy(message, msg, strlen(msg));
    }
  }

  ~thread_data_t() { cout << "Deconstructor\n"; }
  int get_id() { return thread_id; }
  char *get_msg() { return message; }
};

// struct thread_data {
//   int thread_id;
//   const char *message;
// };

void *PrintHello(void *threadarg) {
  (void)threadarg;
  cout << "print hello\n";
  thread_data_t *P1 = (thread_data_t *)threadarg;
  // shared_ptr<thread_data_t> P1 = shared_ptr<thread_data_t> threadarg;
  // struct thread_data *my_data;
  // my_data = (struct thread_data *)threadarg;

  cout << "Thread ID : " << P1->get_id();
  cout << " Message : " << P1->get_msg() << endl;
  sleep(3);
  cout << "print hello (2)\n";
  pthread_exit(NULL);
}

int main() {
  pthread_t thread;
  (void)thread;

  thread_data_t *P1 = new thread_data_t(100);
  (void)P1;

  // struct thread_data td[NUM_THREADS];
  int rc;
  // int i;

  // for (i = 0; i < NUM_THREADS; i++) {
  //   cout << "main() : creating thread, " << i << endl;
  //   td[i].thread_id = i;
  //   td[i].message = "This is message";
  //   rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
  rc = pthread_create(&thread, NULL, PrintHello, (void *)P1);
  cout << "created\n";

  // sleep(5);
  //   if (rc) {
  //     cout << "Error:unable to create thread," << rc << endl;
  //     exit(-1);
  //   }
  // }
  // pthread_exit(NULL);
}