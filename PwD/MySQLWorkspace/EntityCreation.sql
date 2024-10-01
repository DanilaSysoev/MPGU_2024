CREATE TABLE IF NOT EXISTS Entity (
    EntityId INT AUTO_INCREMENT PRIMARY KEY,
    EntityName CHAR(64) NOT NULL,
    EntityGroupId INT NOT NULL,
    FOREIGN KEY (EntityGroupId) REFERENCES EntityGroup(EntityGroupId)
);
