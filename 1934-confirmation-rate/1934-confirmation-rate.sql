SELECT
    s.user_id,
    ROUND(
        IFNULL(
            (
                SELECT COUNT(*)
                FROM Confirmations c
                WHERE c.user_id = s.user_id
                  AND c.action = 'confirmed'
            ) * 1.0 /
            (
                SELECT COUNT(*)
                FROM Confirmations c
                WHERE c.user_id = s.user_id
            ),
            0
        ),
        2
    ) AS confirmation_rate
FROM Signups s;