#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QSpinBox>


#define MAXIMUM_MATRIX_SIZE 49

#define DEFAULT_SIZE_MATRIX 3

#define SPINBOX_SIZE 35


namespace Ui {
class DataDialog;
}

class DataDialog : public QWidget
{
    Q_OBJECT

public:
    explicit DataDialog(QWidget *parent = nullptr);
    ~DataDialog();

public:
    void get_matrix(QList<QList<int>> &arr_matrix);

private:
    int old_matrix_size, new_matrix_size;

    bool state_complete_or_cancel;

    QList<QList<int>>   matrix;

private:
    void clear_table_view();

    void set_table_view_options(int count);

    void add_spinboxes(int count, bool default_val=false);

    void set_matrix(int count, bool default_val=false);

    void set_index_combo_box(int index);

    void scraping_spinboxes();

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void ok_clicked();

    void cancel_cliced();

    void close_clicked();

private slots:
    void on_CBMatrixSize_activated(int index);

    void on_pBtnOk_clicked();

    void on_pBtnCancel_clicked();

private:
    Ui::DataDialog *ui;
    QSpinBox *spinbox;
};


#endif // DATADIALOG_H
