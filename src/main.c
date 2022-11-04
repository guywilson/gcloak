#include <gtk/gtk.h>

static void activate(GtkApplication * app, gpointer user_data)
{
    GtkWidget *         mainWindow;
    GtkWidget *         mainGrid;
    GtkWidget *         image;
    GtkWidget *         capacityLabel;
    GtkWidget *         imageBox;
    GtkWidget *         actionBox;
    GtkWidget *         imageFrame;
    GtkWidget *         actionFrame;
    GtkWidget *         mergeButton;
    GtkWidget *         extractButton;
    GtkWidget *         encryptionFrame;
    GtkWidget *         encryptionBox;
    GtkWidget *         aesBox;
    GtkWidget *         xorBox;
    GtkWidget *         aesEncryptionRadio;
    GtkWidget *         xorEncryptionRadio;
    GtkWidget *         noneEncryptionRadio;
    GtkWidget *         aesPasswordField;
    GtkWidget *         xorKeystreamField;
    GtkWidget *         xorBrowseButton;
    GtkWidget *         qualityFrame;
    GtkWidget *         qualityBox;
    GtkWidget *         highQualityRadio;
    GtkWidget *         mediumQualityRadio;
    GtkWidget *         lowQualityRadio;
    GdkPixbuf *         pixbuf;

    mainWindow = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(mainWindow), "Cloak");

    mainGrid = gtk_grid_new();

    imageFrame = gtk_frame_new(NULL);
    imageBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

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

    actionFrame = gtk_frame_new(NULL);

    actionBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

    mergeButton = gtk_button_new_with_mnemonic("_Merge...");
    extractButton = gtk_button_new_with_mnemonic("_Extract...");

    gtk_box_append(GTK_BOX(actionBox), mergeButton);
    gtk_box_append(GTK_BOX(actionBox), extractButton);

    gtk_box_set_homogeneous(GTK_BOX(actionBox), FALSE);

    gtk_widget_set_halign(actionBox, GTK_ALIGN_CENTER);

    gtk_widget_set_margin_top(actionBox, 10);
    gtk_widget_set_margin_bottom(actionBox, 10);
    gtk_widget_set_margin_start(actionBox, 10);
    gtk_widget_set_margin_end(actionBox, 10);

    gtk_frame_set_child(GTK_FRAME(actionFrame), actionBox);

    gtk_widget_set_margin_top(actionFrame, 0);
    gtk_widget_set_margin_bottom(actionFrame, 10);
    gtk_widget_set_margin_start(actionFrame, 10);
    gtk_widget_set_margin_end(actionFrame, 10);

    /*
    ** Encryption
    */
    encryptionFrame = gtk_frame_new("Encryption");
    encryptionBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    aesEncryptionRadio = gtk_check_button_new_with_label("AES");
    xorEncryptionRadio = gtk_check_button_new_with_label("XOR");
    noneEncryptionRadio = gtk_check_button_new_with_label("None");

    gtk_check_button_set_group(GTK_CHECK_BUTTON(xorEncryptionRadio), GTK_CHECK_BUTTON(aesEncryptionRadio));
    gtk_check_button_set_group(GTK_CHECK_BUTTON(noneEncryptionRadio), GTK_CHECK_BUTTON(aesEncryptionRadio));

    aesBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    aesPasswordField = gtk_password_entry_new();

    gtk_box_append(GTK_BOX(aesBox), aesEncryptionRadio);
    gtk_box_append(GTK_BOX(aesBox), aesPasswordField);

    xorBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    xorKeystreamField = gtk_entry_new();
    xorBrowseButton = gtk_button_new_with_label("Browse...");

    gtk_box_append(GTK_BOX(xorBox), xorEncryptionRadio);
    gtk_box_append(GTK_BOX(xorBox), xorKeystreamField);
    gtk_box_append(GTK_BOX(xorBox), xorBrowseButton);

    gtk_check_button_set_active(GTK_CHECK_BUTTON(aesEncryptionRadio), TRUE);

    gtk_box_append(GTK_BOX(encryptionBox), aesBox);
    gtk_box_append(GTK_BOX(encryptionBox), xorBox);
    gtk_box_append(GTK_BOX(encryptionBox), noneEncryptionRadio);

    gtk_box_set_homogeneous(GTK_BOX(encryptionBox), FALSE);

    gtk_widget_set_margin_top(encryptionBox, 10);
    gtk_widget_set_margin_bottom(encryptionBox, 10);
    gtk_widget_set_margin_start(encryptionBox, 10);
    gtk_widget_set_margin_end(encryptionBox, 10);

    gtk_frame_set_child(GTK_FRAME(encryptionFrame), encryptionBox);

    gtk_widget_set_margin_top(encryptionFrame, 10);
    gtk_widget_set_margin_bottom(encryptionFrame, 10);
    gtk_widget_set_margin_start(encryptionFrame, 0);
    gtk_widget_set_margin_end(encryptionFrame, 10);

    /*
    ** Quality
    */
    qualityFrame = gtk_frame_new("Quality");
    qualityBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    highQualityRadio = gtk_check_button_new_with_label("High (1-bit");
    mediumQualityRadio = gtk_check_button_new_with_label("Medium (2-bits)");
    lowQualityRadio = gtk_check_button_new_with_label("Low (4-bits)");

    gtk_check_button_set_group(GTK_CHECK_BUTTON(mediumQualityRadio), GTK_CHECK_BUTTON(highQualityRadio));
    gtk_check_button_set_group(GTK_CHECK_BUTTON(lowQualityRadio), GTK_CHECK_BUTTON(highQualityRadio));

    gtk_check_button_set_active(GTK_CHECK_BUTTON(highQualityRadio), TRUE);

    gtk_box_append(GTK_BOX(qualityBox), highQualityRadio);
    gtk_box_append(GTK_BOX(qualityBox), mediumQualityRadio);
    gtk_box_append(GTK_BOX(qualityBox), lowQualityRadio);

    gtk_box_set_homogeneous(GTK_BOX(qualityBox), FALSE);

    gtk_widget_set_margin_top(qualityBox, 10);
    gtk_widget_set_margin_bottom(qualityBox, 10);
    gtk_widget_set_margin_start(qualityBox, 10);
    gtk_widget_set_margin_end(qualityBox, 10);

    gtk_frame_set_child(GTK_FRAME(qualityFrame), qualityBox);

    gtk_widget_set_margin_top(qualityFrame, 0);
    gtk_widget_set_margin_bottom(qualityFrame, 10);
    gtk_widget_set_margin_start(qualityFrame, 0);
    gtk_widget_set_margin_end(qualityFrame, 10);

    gtk_grid_attach(GTK_GRID(mainGrid), imageFrame, 0, 0, 1, 3);
    gtk_grid_attach(GTK_GRID(mainGrid), actionFrame, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(mainGrid), encryptionFrame, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(mainGrid), qualityFrame, 1, 1, 1, 1);

    gtk_window_set_child(GTK_WINDOW(mainWindow), mainGrid);

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
