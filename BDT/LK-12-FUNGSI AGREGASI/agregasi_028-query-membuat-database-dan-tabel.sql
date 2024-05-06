-- Membuat database agregasi_028
CREATE DATABASE agregasi_028

-- menggunakan database agregasi_028
USE agregasi_028;

-- Membuat tabel Departemen terlebih dahulu karena tabel lain bergantung pada ini
CREATE TABLE Departemen (
  DNama VARCHAR(255),
  DNumber INT AUTO_INCREMENT PRIMARY KEY,
  MGRSSN VARCHAR(255) NULL,
  MGR_TGL DATE,
  INDEX (MGRSSN)
);

-- Membuat tabel Employee, yang bergantung pada Departemen
CREATE TABLE Employee (
  SSN VARCHAR(255) PRIMARY KEY,
  Nama VARCHAR(255),
  Alamat VARCHAR(255),
  Telepon VARCHAR(255),
  DNO INT,
  SuperSSN VARCHAR(255) NULL,
  Gaji DECIMAL(10, 2),
  Jenis_Kelamin CHAR(1),
  FOREIGN KEY (DNO) REFERENCES Departemen(DNumber),
  FOREIGN KEY (SuperSSN) REFERENCES Employee(SSN),
  INDEX (DNO),
  INDEX (SuperSSN)
);

-- Update tabel Departemen untuk menambahkan foreign key setelah Employee dibuat
ALTER TABLE Departemen
  ADD CONSTRAINT FK_Departemen_MGRSSN FOREIGN KEY (MGRSSN) REFERENCES Employee(SSN);

-- Membuat tabel Project
CREATE TABLE Project (
  PNumber INT AUTO_INCREMENT PRIMARY KEY,
  PName VARCHAR(255),
  Lokasi_P VARCHAR(255),
  DNum INT,
  FOREIGN KEY (DNum) REFERENCES Departemen(DNumber),
  INDEX (DNum)
);

-- Membuat tabel Bekerja
CREATE TABLE Bekerja (
  ESSN VARCHAR(255),
  PNo INT,
  Jam DECIMAL(5,2),
  PRIMARY KEY (ESSN, PNo),
  FOREIGN KEY (ESSN) REFERENCES Employee(SSN),
  FOREIGN KEY (PNo) REFERENCES Project(PNumber),
  INDEX (ESSN),
  INDEX (PNo)
);

-- Membuat tabel Keluarga
CREATE TABLE Keluarga (
  ESSN VARCHAR(255),
  Nama_anggota VARCHAR(255),
  Hubungan VARCHAR(255),
  Jenis_Kelamin CHAR(1),
  PRIMARY KEY (ESSN, Nama_anggota),
  FOREIGN KEY (ESSN) REFERENCES Employee(SSN),
  INDEX (ESSN)
);

-- Membuat tabel DEP_LOKASI
CREATE TABLE DEP_LOKASI (
  DNumber INT,
  Alamat_D VARCHAR(255),
  PRIMARY KEY (DNumber, Alamat_D),
  FOREIGN KEY (DNumber) REFERENCES Departemen(DNumber),
  INDEX (DNumber)
);

SELECT ESSN as 'Kode Pegawai', PNo as 'Nomor Proyek', Jam
FROM bekerja;


