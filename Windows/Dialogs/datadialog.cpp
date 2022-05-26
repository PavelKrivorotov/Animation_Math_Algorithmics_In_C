
#include "datadialog.h"
#include "ui_datadialog.h"

//#include <iostream>
//using namespace std;


DataDialog::DataDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataDialog)
{
    ui->setupUi(this);

    for (int ind = 0; ind < DEFAULT_SIZE_MATRIX; ind++) {
        QList<int> arr_row;
        arr_row.fill(0, DEFAULT_SIZE_MATRIX);

        matrix.append(arr_row);
    }

    set_matrix(DEFAULT_SIZE_MATRIX);

    old_matrix_size = DEFAULT_SIZE_MATRIX;
    new_matrix_size = DEFAULT_SIZE_MATRIX;
    state_complete_or_cancel = false;
}

DataDialog::~DataDialog()
{
    delete spinbox;
    delete ui;
}


void DataDialog::closeEvent(QCloseEvent *event) {
    if (! state_complete_or_cancel) {
        set_matrix(old_matrix_size);
        close_clicked();
    }

    state_complete_or_cancel = false;
}


void DataDialog::get_matrix(QList<QList<int>> &arr_matrix) {
    arr_matrix = matrix;
}



// ...

void DataDialog::clear_table_view() {
    ui->TWMatrix->clear();
}


void DataDialog::set_table_view_options(int count) {
    ui->TWMatrix->setRowCount(count);
    ui->TWMatrix->setColumnCount(count);

    ui->TWMatrix->setMaximumWidth(count * SPINBOX_SIZE);
    ui->TWMatrix->setMaximumHeight(count * SPINBOX_SIZE);
    ui->TWMatrix->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}


void DataDialog::add_spinboxes(int count, bool default_val) {
    for (int row = 0; row < count; row++) {
        for (int col = 0; col < count; col++) {
            spinbox = new QSpinBox();

            spinbox->setMaximumWidth(SPINBOX_SIZE);
            spinbox->setMaximumHeight(SPINBOX_SIZE);
            spinbox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

            spinbox->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
            spinbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            spinbox->setFont(QFont("Bookman Old Style", 11));

            spinbox->setMinimum(-99);
            spinbox->setMaximum(99);

            if (default_val) {
                spinbox->setValue(0);
            }

            else {
                spinbox->setValue(matrix[row][col]);
            }

            ui->TWMatrix->setCellWidget(row, col, spinbox);
        }
    }
}


void DataDialog::set_matrix(int count, bool default_val) {
    clear_table_view();
    set_table_view_options(count);
    add_spinboxes(count, default_val);
}


void DataDialog::set_index_combo_box(int index) {
    ui->CBMatrixSize->setCurrentIndex(index);
}


void DataDialog::scraping_spinboxes() {
    matrix.clear();

    for (int row = 0; row < new_matrix_size; row++) {
        QList<int>  arr_row;

        for (int col = 0; col < new_matrix_size; col++) {
            spinbox = new QSpinBox();
            spinbox = static_cast<QSpinBox*>(ui->TWMatrix->cellWidget(row, col));

            int value = spinbox->value();
            arr_row.append(value);
        }

        matrix.append(arr_row);
    }
}



// ...

void DataDialog::on_CBMatrixSize_activated(int index)
{
    new_matrix_size = index + 3;
    set_matrix(new_matrix_size, true);
}


void DataDialog::on_pBtnOk_clicked()
{
    scraping_spinboxes();

    old_matrix_size = new_matrix_size;
    state_complete_or_cancel = true;

    // ...
    ok_clicked();

    this->close();
}


void DataDialog::on_pBtnCancel_clicked()
{
    set_index_combo_box(old_matrix_size - 3);
    set_matrix(old_matrix_size);

    new_matrix_size = old_matrix_size;
    state_complete_or_cancel = true;

    // ...
    cancel_cliced();

    this->close();
}

