CREATE TABLE IF NOT EXISTS `OneFirst` (
    `id` INTEGER PRIMARY KEY AUTO_INCREMENT,
    `name` TEXT NOT NULL,
    `one_second_id` INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS `OneSecond` (
    `id` INTEGER PRIMARY KEY AUTO_INCREMENT,
    `name` TEXT NOT NULL,
    `one_first_id` INTEGER NOT NULL,
    FOREIGN KEY (`one_first_id`) REFERENCES `OneFirst`(`id`)
);

ALTER TABLE `OneFirst`
ADD FOREIGN KEY (`one_second_id`) REFERENCES `OneSecond`(`id`);
