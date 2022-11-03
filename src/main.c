#include <gtk/gtk.h>

static void activate(GtkApplication * app, gpointer user_data)
{
    GtkWidget *         mainWindow;
    GtkWidget *         image;
    GtkWidget *         capacityLabel;
    GtkWidget *         imageBox;
    GtkWidget *         imageFrame;
    GdkPixbuf *         pixbuf;

    mainWindow = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(mainWindow), "Cloak");

    imageBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    imageFrame = gtk_frame_new(NULL);

    pixbuf = gdk_pixbuf_new_from_file_at_size("/Users/guy/development/cloak/test/album.bmp", 500, 500, NULL);
    image = gtk_image_new_from_pixbuf(pixbuf);

    gtk_widget_set_size_request(image, 400, 400);

    capacityLabel = gtk_label_new_with_mnemonic("_Capacity: ");
    gtk_widget_set_halign(capacityLabel, GTK_ALIGN_START);

    gtk_box_append(GTK_BOX(imageBox), image);
    gtk_box_append(GTK_BOX(imageBox), capacityLabel);

    gtk_box_set_homogeneous(GTK_BOX(imageBox), FALSE);

    gtk_widget_set_margin_top(imageBox, 10);
    gtk_widget_set_margin_bottom(imageBox, 10);
    gtk_widget_set_margin_start(imageBox, 10);
    gtk_widget_set_margin_end(imageBox, 10);

    gtk_frame_set_child(GTK_FRAME(imageFrame), imageBox);

    gtk_widget_set_margin_top(imageFrame, 10);
    gtk_widget_set_margin_bottom(imageFrame, 10);
    gtk_widget_set_margin_start(imageFrame, 10);
    gtk_widget_set_margin_end(imageFrame, 10);

    gtk_window_set_child(GTK_WINDOW(mainWindow), imageFrame);

    gtk_widget_set_halign(mainWindow, GTK_ALIGN_START);
    gtk_widget_set_valign(mainWindow, GTK_ALIGN_CENTER);

    gtk_widget_show(mainWindow);
}

int main(int argc, char ** argv)
{
    GtkApplication *        app;
    int                     status;

    app = gtk_application_new("com.guy.cloak", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    return status;
}
