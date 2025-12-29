#include <gtk/gtk.h>
#include <stdio.h>

int AddNumber(int firstNumber, int secondNumber);
int SubtractNumber(int firstNumber, int secondNumber);
int MultiplyNumber(int firstNumber, int secondNumber);
int DivideNumber(int firstNumber, int secondNumber);
static void on_activate(GtkApplication *app, gpointer user_data);

void initializecalculator();

int main(int argc, char *argv[]) {
  // initializecalculator();
  GtkApplication *app;
  int status;

  app =
      gtk_application_new("com.nitesh.calculator", G_APPLICATION_DEFAULT_FLAGS);

  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

void initializecalculator() {
  // take input from the user
  int firstNumber, secondNumber;
  printf("Input the first number: ");
  scanf("%d", &firstNumber);
  printf("Input the second number:");
  scanf("%d", &secondNumber);
  printf("%d\n", AddNumber(firstNumber, secondNumber));
  printf("%d\n", SubtractNumber(firstNumber, secondNumber));
  printf("%d\n", MultiplyNumber(firstNumber, secondNumber));
}

int AddNumber(int firstNumber, int secondNumber) {
  return firstNumber + secondNumber;
}

int SubtractNumber(int firstNumber, int secondNumber) {
  return firstNumber - secondNumber;
}

int MultiplyNumber(int firstNumber, int secondNumber) {
  return firstNumber * secondNumber;
}

int DivideNumber(int firstNumber, int secondNumber) {
  return firstNumber / secondNumber;
}

// GTK CODE

static void on_activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Calculator");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);

  // Create a new button
  GtkWidget *button = gtk_button_new_with_label("Click Me!");

  gtk_window_set_child(GTK_WINDOW(window), button);
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_close),
                           window);

  gtk_window_present(GTK_WINDOW(window));
}
