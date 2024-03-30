CREATE TABLE Students (
    surname VARCHAR(100) NOT NULL,
    count_processor INT NOT NULL,
    processor VARCHAR(100) NOT NULL,
    memory INT NOT NULL,
    videocontroller VARCHAR(100) NOT NULL,
    videomemory DECIMAL(4,2) NOT NULL,  -- Исправлено на DECIMAL(4,2)
    winchester VARCHAR(100) NOT NULL,
    count_winchester INT NOT NULL,
    volume_winchester INT NOT NULL,
    count_int_controller INT NOT NULL,
    count_perifery_device INT NOT NULL,
    os VARCHAR(100) NOT NULL
);

INSERT INTO Students (surname, count_processor, processor, memory, 
    videocontroller, videomemory, winchester, count_winchester,
    volume_winchester, count_int_controller, count_perifery_device, os)
VALUES
('Bolotin', 1, 'Intel', 8, 'built-in', 1.00, 'SATA', 1, 500, 3, 5, 'Windows'),
('Vlasko', 1, 'AMD', 16, 'external', 2.00, 'SATA', 2, 1024, 2, 4, 'Linux'),
('Gavrilov', 1, 'Intel', 32, 'AGP', 4.00, 'IDE', 1, 2048, 1, 3, 'Windows'),
('Ganyak', 1, 'AMD', 64, 'PCI', 8.00, 'SATA', 3, 500, 4, 6, 'macOS'),
('Grigoriev', 1, 'Intel', 4, 'built-in', 0.50, 'IDE', 1, 250, 2, 2, 'Windows'),
('Denisov', 1, 'AMD', 8, 'PCI', 2.00, 'SATA', 2, 1024, 3, 4, 'Linux'),
('Zhgenti', 1, 'Intel', 16, 'built-in', 1.00, 'SATA', 1, 500, 2 ,3, 'Windows'),
('Ivanov', 1, 'AMD', 32, 'AGP', 4.00, 'IDE', 1, 2048, 1, 4, 'Windows'),
('Ismailova', 1, 'Intel', 64, 'PCI', 8.00, 'SATA', 3, 500, 4, 6, 'macOS'),
('Kuleshov', 1, 'AMD', 4, 'built-in', 0.50, 'IDE', 1, 250, 2, 2, 'Windows');

SELECT * FROM Students
WHERE NOT (processor = 'Intel' AND os = 'Windows')
GROUP BY surname;