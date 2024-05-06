-- menggunakan database agregasi_028
USE agregasi_028;

-- Masukkan data ke tabel Departemen
INSERT INTO Departemen (DNama, DNumber, MGRSSN, MGR_TGL) VALUES
('Tahpidz', 1, NULL, '2020-01-01'),  -- Kosongkan MGRSSN sementara
('PSDM', 2, NULL, '2020-06-15'),
('Bisnis', 3, NULL, '2020-08-23');

-- Masukkan data ke tabel Employee
INSERT INTO Employee (SSN, Nama, Alamat, Telepon, DNO, SuperSSN, Gaji, Jenis_Kelamin) VALUES
('123-45-6789', 'Zizik', 'Dieng', '0821-3234-0813', 1, NULL, 75000, 'L'),
('987-65-4321', 'Qibs', 'Dinoyo 865', '0857-4134-5123', 2, '123-45-6789', 60000, 'P'),
('456-78-9012', 'Uhan', 'Rusun UB', '0823-2314-6377', 3, '987-65-4321', 65000, 'P'),
('321-54-9876', 'Rakha', 'Suhat', '0851-2345-9876', 1, '123-45-6789', 55000, 'L');


-- Update MGRSSN di Departemen setelah Employee dibuat
UPDATE Departemen SET MGRSSN = '123-45-6789' WHERE DNumber = 1;
UPDATE Departemen SET MGRSSN = '987-65-4321' WHERE DNumber = 2;
UPDATE Departemen SET MGRSSN = '456-78-9012' WHERE DNumber = 3;



-- Insert data ke tabel Project
INSERT INTO Project (PNumber, PName, Lokasi_P, DNum) VALUES
(101, 'Studi Banding', 'UGM', 1),
(102, 'Tahfidz Camp', 'Batu', 1),
(103, 'Rihlah', 'Kebon Rojo', 2);

-- Insert data ke tabel Bekerja
INSERT INTO Bekerja (ESSN, PNo, Jam) VALUES
('123-45-6789', 101, 3.5),
('987-65-4321', 103, 50.0),
('456-78-9012', 102, 240.0),
('321-54-9876', 101, 3.5);

-- Insert data ke tabel Keluarga
INSERT INTO Keluarga (ESSN, Nama_anggota, Hubungan, Jenis_Kelamin) VALUES
('123-45-6789', 'Putri', 'Istri', 'P'),
('987-65-4321', 'Apps', 'Suami', 'L'),
('456-78-9012', 'Danish', 'Anak', 'L');

-- Insert data ke tabel DEP_LOKASI
INSERT INTO DEP_LOKASI (DNumber, Alamat_D) VALUES
(1, 'Sekretariat 867'),
(2, 'Rooftop 911'),
(3, 'Basement 433');

